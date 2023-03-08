/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjcho <hyunjcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:21:11 by hyunjcho          #+#    #+#             */
/*   Updated: 2023/01/16 21:43:04 by hyunjcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 3
int main(int, char**)
{
    // const Array<int> arr(3);
    // std::cout << arr[1] << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    // SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

    Array<int> tmmmmmp = numbers;
    for (int i = 0; i < 5; i++) {
        std::cout << "numbers[i] = " << numbers[i] << std::endl;
        std::cout << "tmmmmmp[i] = " << tmmmmmp[i] << std::endl;
    }
    std::cout << "=======================================================\n\n";
    for (int i = 0; i < 5; i++)
        tmmmmmp[i] = i;
    for (int i = 0; i < 5; i++) {
        std::cout << "numbers[i] = " << numbers[i] << std::endl;
        std::cout << "tmmmmmp[i] = " << tmmmmmp[i] << std::endl;
    }
    return 0;
}