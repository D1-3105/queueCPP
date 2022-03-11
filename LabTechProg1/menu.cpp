#include "menu.h"
#include "queueSon.h"
int choice() {
	int c;
	print("1 - EXHERITATION TYPE public");
	print("2 - EXHERITATION TYPE protected");
	print("3 - EXHERITATION TYPE private");
	std::cin >> c;
	return c;
}


void menu() {
	int type = choice();
	switch (type) {
	case 1: {
		publicSon pub;
		chosenClass(pub);
		break;
	}
	case 2:
		break;
	case 3:
		break;
	default:
		menu();
	}
}

template<class T>
void chosenClass(T &q) {
	while(true){
		print("1 - Push queue");
		print("2 - Pop queue");
		print("3 - Print queue");
		print("4 - Count even");
		print("5 - Copy me");
		print("6 - Merge me");
		print("7 - End");
		int choice;
		std::cin >> choice;
		switch(choice) {
		case 1:
			print("Input:", 0);
			int val;
			std::cin >> val;
			q.push(val);
			break;
		case 2:
			print("Output:", 0);
			if (!q.isEmpty())
				print(q.pop());
			else
				print("Queue is empty!");
			break;
		case 3:
			print(q.toString());
			break;
		case 4:
			print(q.count());
			break;
		case 5: {
			print("Enter a queue:");
			T q1;
			int val;
			while (std::cin.get()!='.') {
				std::cin >> val;
				q1.push(val);
			}
			q.copy(q1);
			break;
		}
		case 6: {
			print("Enter a queue:");
			T q1;
			getchar();
			while (std::cin.get() != '.') {
				std::cin >> val;
				q1.push(val);
			}
			print("Mergable (selected): " + q.toString());
			print("Merged:", 0);
			q1.merge(q);
			break;
		}
		case 7:
			exit(0);
		default:
			chosenClass(q);
		}
		print("\n");
	}
}