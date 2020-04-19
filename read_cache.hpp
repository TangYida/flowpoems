#include<glibmm.h>
#include<bits/stdc++.h>

using lists = std::map<int,std::string>;
const std::string Dot{"，"};
const std::string End{"。"};
#define SR srand((unsigned)time(0))
#define RD ((rand()&0x3)<<30 | rand()<<15 | rand())
static std::ifstream in;
/*TODO*/
static void addFromFile(std::string file,
		lists& nouns,
		lists& verbs)
{
	file += ".image";
	in.open(file);

	std::string line;
	lists* ptr;

	while(in >> line) {
		if(line == "#nouns") ptr = &nouns;
		else if(line == "#verbs") ptr = &verbs;
		else ptr->insert({RD,line});
	}
}
