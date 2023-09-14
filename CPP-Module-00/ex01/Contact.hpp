/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:03:45 by bmengouc          #+#    #+#             */
/*   Updated: 2023/08/21 17:03:46 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nick_name;
		std::string _phone_number;
		std::string _dark_secret;
		int			idx;
	public:
		std::string	get_fname();
		std::string	get_lname();
		std::string	get_nname();
		std::string	get_pnum();
		std::string	get_dsercet();
		void		add_contact(int idx);
		void		set_fname(std::string fn);
		void		set_lname(std::string ln);
		void		set_nname(std::string nn);
		void		set_pnum(std::string pn);
		void		set_dsercet(std::string ds);
		int			getIdx();
		void		setIdx(int idx);
};

#endif
