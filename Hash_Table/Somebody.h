

#pragma once

#include <iostream>
#include <string>
#include <functional>

class Somebody;

std::ostream& operator<<(std::ostream& out_stream, const Somebody& someone);


class Somebody
{
public:
	std::string first_name;
	std::string last_name;
	std::string description;
	Somebody() {};
	Somebody(std::string first, std::string last, std::string script);
	~Somebody() {};

};



Somebody::Somebody(std::string first, std::string last, std::string script)
{
	first_name = first;
	last_name = last;
	description = script;
}


namespace std
{
	template <>
	struct hash<Somebody>
	{
		std::size_t operator() (const Somebody& someone) const
		{
			using std::size_t;
			using std::string;
			using std::hash;

			size_t h1 = hash<string>()(someone.first_name);
			size_t h2 = hash<string>()(someone.last_name);

			return h1 + h2;
		}

	};

}

bool operator== (const Somebody& someone_a, const Somebody& someone_b)
{
	bool first = false;
	bool second = false;
	bool third = false;

	if (someone_a.first_name == someone_b.first_name)
		first = true;

	if (someone_a.last_name == someone_b.last_name)
		second = true;

	if (someone_a.description == someone_b.description)
		third = true;

	return (first && second && third);
}

std::ostream& operator<<(std::ostream& out_stream, const Somebody& someone)
{
	std::cout << someone.first_name << " " << someone.last_name << "\n" << someone.description;
	return out_stream;
}

