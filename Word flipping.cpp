#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

void reverseword() {
	int num = 0;
	deque<char> deq;

	scanf("%d\n", &num);
	while(num--) {
		char cmd[1024] = {0,};

		fgets(cmd, sizeof(cmd) - 1, stdin);

		char *ptr = cmd;
		while (true) {
			if (*ptr == ' ') {
				while (deq.size()) {
					putc(deq.back(), stdout);
					deq.pop_back();
				}
				fputc(' ', stdout);
			} else if (*ptr == '\0' || *ptr == '\n') {
				while (deq.size()) {
					putc(deq.back(), stdout);
					deq.pop_back();
				}
				printf("\n");
				break;
			} else {
				deq.push_back(*ptr);
			}
			ptr++;
		}
	}
}

int main(void) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	reverseword();

#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}

