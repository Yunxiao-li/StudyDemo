//////////////////////////////////////////////////////////////////////////
/*
The file introduces some basic knowledge about c++11 thread 
*/
//////////////////////////////////////////////////////////////////////////
#pragma once

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <queue>

using namespace std;

// thread function
// no parameter
void ThreadFoo1()
{
    std::cout << __FUNCTION__ << " thread id: " << this_thread::get_id() << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
}
// with parameter
void ThreadFoo2(int i)
{
	std::cout << __FUNCTION__ << " value: " << i << " thread id: " << this_thread::get_id() << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
}
// functor
struct MyFunctor
{
	void operator()()
	{
		std::cout << __FUNCTION__ << " thread id: " << this_thread::get_id() << std::endl;
	}
};

// bind class member function
struct Worker
{
	void run(int i)
	{
		std::cout << __FUNCTION__ << " value: " << i << " thread id: " << this_thread::get_id() << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
};

// mutex , condition_variable
// producer-consumer patten, 1 producer, 1 buffer, 1 consumer

std::mutex mtx_producer, mtx_consumer;
std::condition_variable cv_producer, cv_consumer;
std::queue<int> q;
bool bquit = false;

void producer()
{
	int i = 0;
	while (!bquit)
	{
		std::unique_lock<std::mutex> ulk_producer(mtx_producer);
		cv_consumer.wait(ulk_producer);

		std::cout << "producer: " << i << std::endl;
		q.push(i++);

		cv_producer.notify_one();
	}
}

void consumer()
{
	int n = 0;
	while (1)
	{
		std::unique_lock<std::mutex> ulk_consumer(mtx_consumer);
		cv_producer.wait(ulk_consumer);

		if (q.empty())
		{
			return;
		}
		n = q.front();
		std::cout << "consumer: " << n << std::endl << std::endl;
		q.pop();

		cv_consumer.notify_one();
	}
}

void testThread2()
{
	std::thread t_producer(producer);
	std::thread t_consumer(consumer);
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	// begin to produce
	cv_consumer.notify_one();
	// producing
	std::this_thread::sleep_for(std::chrono::seconds(2));
	// quit
	bquit = true;
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	cv_producer.notify_one();
	t_producer.join();
	t_consumer.join();
}


