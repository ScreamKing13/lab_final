#include <getopt.h>
#include <iostream>
#include <set>
#include <string>
#include <iterator>
using namespace std;


set<string> ProcessArgs(int argc, char** argv)
{	
	string expr;
	set <string> argsList;
	const char* const short_opts = "V:Sl::Eh";
    const option long_opts[] = {
            {"version", required_argument, nullptr, 'V'},
            {"something", no_argument, nullptr, 'S'},
            {"list", optional_argument, nullptr, 'l'},
            {"everything", no_argument, nullptr, 'E'},
            {"help", no_argument, nullptr, 'h'},
            {nullptr, no_argument, nullptr, 0}
    };

    while (true)
    {
        const auto opt = getopt_long(argc, argv, short_opts, long_opts, nullptr);

        if (-1 == opt)
            break;

        switch (opt)
        {
        case 'V':
			expr = "version of something is " + string(optarg);
            break;

        case 'S':
			expr = "This does something...\nMaybe.";
            break;

        case 'l':
			if (optarg != NULL) {
				expr = "listing " + string(optarg) + " elements...";
			} else {
				expr = "listing ALL elements...";
			}
            break;

        case 'E':
            expr = "does EVERYTHING.\nyup, without arguments.";
            break;

        case 'h': // -h or --help
			expr = "--num <n>:           Set number of program\n"
            	   "--beep:              Beep the user\n"
            	   "--sigma <val>:       Set sigma of program\n"
            	   "--writeFile <fname>: File to write to\n"
            	   "--help:              Show help\n";
			break;
        case '?':
			expr = "unknown parameter " + string(optarg);
			break;
        }
		argsList.insert(expr);
    }
	return argsList;
}

int main(int argc, char **argv)
{
    set<string> result = ProcessArgs(argc, argv);
	set <string> :: iterator it;
	for (it = result.begin(); it != result.end(); ++it)
		cout << *it << "\n";
    return 0;
}