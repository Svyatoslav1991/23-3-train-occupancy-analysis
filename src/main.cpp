#include <iostream>

constexpr auto N = 10;
constexpr auto MAX_PASSENGERS = 20;

//Checking the carriage for overcrowding with passengers
constexpr bool isCrowded(int64_t passengers, int64_t value) noexcept
{
	return passengers > value;
}

//********************************************************************************

//Checking the carriage for empty seats
constexpr bool isEmpty(int64_t passengers, int64_t value) noexcept
{
	return passengers < value;
}

//********************************************************************************

#define fillArr(arr, size) \
for(int64_t i = 0; i < size; ++i)\
{\
	do\
	{\
		std::cout << "Carriage number " << i + 1 << " (0 - 100)\nEnter value:"; \
		std::cin >> arr[i]; \
	} while (arr[i] < 0 || arr[i] > 100);\
}\

//********************************************************************************

#define callPredicate(foo, arr, size, value, string) \
for(int64_t i = 0; i < size; ++i) { \
	if (foo(arr[i], value))	\
	{	\
		std::cout << "Carriage " << i + 1 << " " << string << "\n"; \
	}	\
}

//********************************************************************************

#define sumArr(arr, size, sum) \
for(int64_t i = 0; i < size; ++i) \
{\
	sum += arr[i]; \
}

//********************************************************************************

int main()
{
	std::cout << "\tTASK 23.3 TRAIN OCCUPANCY_ANALYSIS\n\n";

	int64_t train[N];

	std::cout << "Fill the wagons with people (from 0 to 50)\n";
	fillArr(train, N);

	std::cout << "\n";

	callPredicate(isCrowded, train, N, MAX_PASSENGERS, "is crowded");

	std::cout << "\n";

	callPredicate(isEmpty, train, N, MAX_PASSENGERS, "has empty places");

	int64_t sum = 0;
	sumArr(train, N, sum);

	std::cout << "\nThe total number of passengers is " << sum << "\n";



	return 0;
}
