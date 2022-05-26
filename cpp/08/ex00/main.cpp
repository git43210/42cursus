/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daypark <daypark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 22:26:53 by daypark           #+#    #+#             */
/*   Updated: 2022/05/27 03:03:24 by daypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() {
    std::vector<int> v;

    for (int i = 0; i < 5; i++) {
        v.push_back(i);
    }

    try {
        std::vector<int>::iterator result = easyfind(v, 3);
        std::cout << *result << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}