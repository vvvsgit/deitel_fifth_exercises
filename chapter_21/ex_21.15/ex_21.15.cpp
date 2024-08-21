#include <iostream>
#include <queue>

int getTime()
{
    return rand() % 4 + 1;
}

int 
main()
{
    std::cout << std::endl;

    std::srand(time(0));

    std::queue<int> customer;
    int arrivalTime = getTime();
    int serviceTime = getTime();
    int leavingTime = arrivalTime + serviceTime;
    customer.push(leavingTime);

    int maxSize = customer.size();
    int maxWait = serviceTime;

    for (int minutes = arrivalTime; minutes < 720; ++minutes) {
        if (minutes == arrivalTime) {
            arrivalTime += getTime();
            serviceTime = getTime();
            if (arrivalTime > leavingTime) {
                leavingTime = arrivalTime + serviceTime;
            } else {
                leavingTime = leavingTime + serviceTime;
            }
            customer.push(leavingTime);
            if (maxSize < customer.size()) {
                maxSize = customer.size();
            }
            if (maxWait < leavingTime - arrivalTime) {
                maxWait = leavingTime - arrivalTime;
            }
        }
        if (minutes == customer.front()) {
            customer.pop();
        }
    }
    while (!customer.empty()) {
        customer.pop();
    }
    std::cout << "Max size of queue is " << maxSize << " customer." << std::endl;
    std::cout << "Longest wait is " << maxWait << " minutes." << std::endl;

    std::cout << std::endl;
    return 0;
}

