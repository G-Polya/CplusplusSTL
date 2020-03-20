#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <random>

#include "header.h"
#include "header2.h"

using namespace std;
using distribution = uniform_int_distribution<>;

void histogram(const vector<int>& v, int min)
{
	string bar(60, '*');

	for (size_t i = 0; i < v.size(); i++)
	{
		cout << setw(3) << i * min << " "
			<< setw(4) << v[i] << " "
			<< bar.substr(0, v[i])
			<< (v[i] > static_cast<int>(bar.size()) ? "..." : "")
			<< endl;
	}
}

int main()
{
	random_device random_n;

	int service_t_min = 2, service_t_max = 15;
	distribution service_t_d{ service_t_min, service_t_max };

	int min_customers = 15, max_customers = 20;
	distribution n_1st_customers_d{ min_customers, max_customers };

	int min_arr__interval = 1, max_arr_interval = 5;
	distribution arrival_interval_d{ min_arr__interval, max_arr_interval };

	size_t n_checkouts = 0;
	cout << "마트 계산대 개수 입력: ";
	cin >> n_checkouts;
	if (!n_checkouts)
	{
		cout << "계산대 개수는 1이상이어야 합니다. 1로 설정합니다." << endl;
		n_checkouts = 1;
	}

	vector<Checkout> checkouts{ n_checkouts };
	vector<int> service_times(service_t_max - service_t_min + 1);

	int count = n_1st_customers_d(random_n);
	cout << "마트 개점 시에 대기 고객 수 : " << count << endl;
	int added = 0;
	int service_t = 0;
	while (added++ < count)
	{
		service_t = service_t_d(random_n);
		std::min_element(begin(checkouts), end(checkouts))->add(Customer(service_t));
		++service_times[service_t - service_t_min];
	}

	size_t time = 0;
	const size_t total_time = 600;
	size_t longest_q = 0;

	int new_cust_interval{ arrival_interval_d(random_n) };

	while (time < total_time)
	{
		++time;
		if (++new_cust_interval == 0)
		{
			service_t = service_t_d(random_n);
			min_element(begin(checkouts), end(checkouts))->add(Customer(service_t));
			++service_times[service_t - service_t_min];

			for (auto& checkout : checkouts)
				longest_q = max(longest_q, checkout.qlength());

			new_cust_interval = arrival_interval_d(random_n);
		}

		for (auto& checkout : checkouts)
			checkout.time_increment();
	}

	cout << "최대 대기열 길이 = " << longest_q << endl;
	cout << "\n서비스 시간 막대 그래프\n";
	histogram(service_times, service_t_min);

	cout << "\n오늘 총 고객 수 :"
		<< accumulate(begin(service_times), end(service_times), 0)
		<< endl;
}