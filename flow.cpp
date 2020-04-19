#include<glibmm.h>
#include "read_cache.hpp"

extern void addFromFile(std::string,lists&,lists&);

lists nouns,verbs;

static inline void replaceBegin(lists& list)
{
	auto begin = *list.begin();
	list.erase(list.begin());
	list.insert({RD,begin.second});
}

static inline void replaceEnd(lists& list)
{
	auto end = *list.rbegin();
	auto endPtr = list.end();
	list.erase(--endPtr);
	list.insert({RD,end.second});
}

static void makeItOut(unsigned line)
{
	unsigned para,rem{line};
	/*FIXME*/
	for(para = RD % rem % 10 + 1;rem;
			(rem -= para) && (para = RD % rem % 10 + 1)) {
		for(int i = 1;i <= para;i++) {
			if(RD % 3) {
				std::cout << verbs.begin()->second <<
					nouns.rbegin()->second;
			} else {
				std::cout <<  nouns.begin()->second
					<< verbs.begin()->second
					<< nouns.rbegin()->second;
			}
			std::cout << (i < para ? Dot : End) << "\n";
			replaceEnd(nouns);
			replaceBegin(verbs);
			if(!(RD % 5)) replaceBegin(nouns);
		}
		std::cout << "\n";
	}
}

static inline void help()
{
	std::cout << "flowpoems:a stupid poems creater\n"
		"This application allows you to create poems using the computer.\n"
		"Commands:\n"
		"\thelp: Print this massage.\n"
		"\tread [image file name]: Make the computer read from the image file by which the computer can create poems.For instance,you can type \"read wheat\".\n"
		"\tline [number]: Point out the length of your poem.\n"
		"\tmake: Make the poem and print it on the screen.\n"
		"\texit:Bye Bye.\n";
}

int main()
{
	std::string cmd,args;
	unsigned line{0};

	SR;

	help();

	while(std::cout << ">> " && std::cin >> cmd) {
		if(cmd == "help") help();
		if(cmd == "line") std::cin >> line; /*TODO*/
		if(cmd == "exit") exit(0);
		if(cmd == "read") {
			std::cin >>  args;
			nouns.clear(),verbs.clear();
			addFromFile(args,nouns,verbs);
		}
		if(cmd == "make") { /*TODO to file*/
			if(!nouns.size() || !verbs.size() || line == 0)
				std::cerr << "Something wrong here.\n";
			makeItOut(line);
		}
	}
	exit(19260817);
}
