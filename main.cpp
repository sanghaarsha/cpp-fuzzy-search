#include "search.h"
#include "util.h"

using namespace std;

int main() {
	DIR *dp;
	ifstream inFile("lab11.txt");
	string query;
	pair<string, string> location;
	bool ran = false;
	int numWords;

	query = getQuery();
	query = trim_string(query);

	while(query != "q") {
		numWords = countWords(query);
		ran = true;
		if((dp = opendir("./content")) != NULL) {
			if (numWords == 1)
				location = wordSearch(dp, query);
			else
				location = phraseSearch(dp, query, numWords);
			printOutput(location);
		}
		else if(dp == NULL) {
			closedir(dp);
			perror("Couldn't open the directory!");
		}
		query = getQuery();
		query = trim_string(query);
	}

	if (ran == true)
		closedir(dp);

	return 0;
}
