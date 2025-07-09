#include <iostream>
#include <thread>
#include <vector>
 
void worker(std::vector<long long>::iterator start, std::vector<long long>::iterator end, long long* result) {
    long long sum = 0;
    for (auto iter = start; iter < end; ++ iter) {
        sum += *iter;
    }
 
    *result = sum;
 
    // thread id
    std::thread::id this_id = std::this_thread::get_id();
    printf("쓰레드 %p 에서 %lld 부터 %lld 까지 계산한 결과 : %lld\n", this_id, *start, *(end - 1), sum);
}
 
int main(void) {
    const int MAX = 1000000;
    std::vector<long long> data(MAX);
    for (int i = 0; i < MAX; i++)
        data[i] = i;
 
    // thread를 이용한 합 구하기
    const int NUM_OF_THRHEAD = 10;
    std::vector<long long> partial_sums(NUM_OF_THRHEAD);
 
    std::vector<std::thread> workers;
    for (int i = 0; i < NUM_OF_THRHEAD; i++) {
        workers.push_back(
            std::thread(
                worker, data.begin() + i * (MAX / NUM_OF_THRHEAD),
                data.begin() + (i + 1) * (MAX / NUM_OF_THRHEAD),
                &partial_sums[i]));
    }
 
    for (int i = 0; i < NUM_OF_THRHEAD; i++)
        workers[i].join();
 
    long long total = 0;
    for (int i = 0; i < NUM_OF_THRHEAD; i++)
        total += partial_sums[i];
 
    std::cout << "Total Sum : " << total << std::endl;
 
    return 0;
}