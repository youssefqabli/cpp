/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-qabl <yel-qabl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:50:24 by yel-qabl          #+#    #+#             */
/*   Updated: 2023/05/10 00:39:02 by yel-qabl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("") {};

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name){
    if (grade < 1)
        throw std::exception();
    else if (grade > 150)
        throw std::exception();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
    *this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other)
        grade = other.getGrade();
    return *this;
}

Bureaucrat::~Bureaucrat() {};

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "The Grade Is Higher Than 1";
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "The Grade Is Lower than 150";
}


std::string Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

void Bureaucrat::increment(int num) {
    if ((grade - num) < 1)   
        throw std::exception();
    grade -= num;
}

void Bureaucrat::decrement(int num) {
    if ((grade + num) > 150)
         throw std::exception();
    grade += num;
}

void    Bureaucrat::signForm(Form &form) {
    try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() <<std::endl;
    }
    catch (const std::exception &e) {
        std::cout << this->getName() << " can't  sign " << form.getName() << " due to " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
    out << "Name: " << bureaucrat.getName() << ", grade: " << bureaucrat.getGrade();
    return out; 
}