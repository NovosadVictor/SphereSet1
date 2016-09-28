#include <iostream>
#include <set>

int main()
{
	std::set<int> s1;
	std::set<int> ::iterator it1;
	std::set<int> s2;
	std::set<int> ::iterator it2;
	std::set<int> s3;
	std::set<int> ::iterator it3;
	int read;
	bool r = false;
	while (std::cin >> read)
	{
		if (read != 0)
			s1.insert(read);
		else
			break;
	}
	while (std::cin >> read)
	{
		if (read != 0)
			s2.insert(read);
		else
			break;
	}

	if (s1.empty())
	{
		for (it2 = s2.begin(); it2 != s2.end(); ++it2)
			std::cout << *it2 << " ";
	}
	if (s2.empty())
	{
		for (it1 = s1.begin(); it1 != s1.end(); ++it1)
			std::cout << *it1 << " ";
	}
	for (it1 = s1.begin(); it1 != s1.end(); ++it1)
	{
		for (it2 = s2.begin(); it2 != s2.end(); ++it2)
			if (s2.count((*it1)))
			{
				r = true;
				break;
			}
		if (!r)
			s3.insert(*it1);
		r = false;
	}
	for (it2 = s2.begin(); it2 != s2.end(); ++it2)
	{
		for (it1 = s1.begin(); it1 != s1.end(); ++it1)
			if (s1.count((*it2)))
			{
				r = true;
				break;
			}
		if (!r)
			s3.insert(*it2);
		r = false;
	}
	if (s3.empty())
		std::cout << "0" << std::endl;
	else
		while (!s3.empty())
		{
			int min = *(s3.begin());
			for (it3 = s3.begin(); it3 != s3.end(); ++it3)
				if (*it3 < min)
					min = *it3;
			std::cout << min << " ";
			s3.erase(min);
		}
	//system("pause");
	return 0;
}

