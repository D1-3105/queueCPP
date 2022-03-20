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
		publicSon pub[3];
		chosenClass(pub);
		break;
	}
	case 2: {
		protectedSon* pub=new protectedSon[3];
		chosenClass(pub);
		break;
	}
	case 3: {
		privateSon* pub= new privateSon[3];
		chosenClass(pub);
		break;
	}
	default:
		menu();
	}
}

template<class T>
void chosenClass(T *q_all) {
	T* selected = &q_all[0];
	T* buffer=&q_all[1];
	T* copied=&q_all[2];
	T tmp;
	while(true){
		print("\t1 - Push queue");
		print("\t2 - Pop queue");
		print("\t3 - Print queue");
		print("\t4 - Count even");
		print("\t5 - Copy me");
		print("\t6 - Merge me");
		print("\t7 - End");
		print("\t8 - Change queue");
		int choice;
		std::cin >> choice;
		switch(choice) {
		case 1: {
			print("Input:", 0);
			int val;
			std::cin >> val;
			selected->push(val);
			break;
		}
		case 2:
			print("Output:", 0);
			if (!selected->isEmpty())
				print(selected->pop());
			else
				print("Queue is empty!");
			break;
		case 3:
			print(selected->toString());
			break;
		case 4:
			print(selected->count());
			break;
		case 5: {
			print("From (0- selected, 1- buffer, 2- copied):", 0);
			int c;
			std::cin >> c;
			print("To (0- selected, 1- buffer, 2- copied):", 0);
			int c1;
			std::cin >> c1;
			q_all[c1].copy(q_all[c]);
			break;
		}
		case 6: {
			print("Merge 1 (0-selected, 1- buffer, 2- copied):", 0);
			int c;
			std::cin >> c;
			T* answers[3] = {selected, buffer, copied};
			
			print("Merge 2 (0- selected, 1- buffer, 2- copied):", 0);
			int c1;
			std::cin >> c1;
			T *result= new T();
			result->merge(*answers[c], *answers[c1]);
			print("Result:"+result->toString());
			print("Wanna save?[y/n]");
			char ans;
			std::cin >> ans;
			if (ans == 'y') {
				buffer = result;
			}
			break;
		}
		case 7:
			exit(0);
			break;
		case 8: {
			print("Swipe queue (s-0, b-1, c-2): ");
			print("Selected: " + selected->toString());
			print("Buffer: "+ buffer->toString());
			print("Copied: "+ copied->toString());
			int c;
			std::cin >> c;
			tmp = *selected;
			*selected = q_all[c];
			q_all[c] = tmp;
			print("Selected: " + selected->toString());
			print("Buffer: "+ buffer->toString());
			print("Copied: "+ copied->toString());
		}
		default:
			chosenClass(q_all);
		}
		print("\n");
	}
}