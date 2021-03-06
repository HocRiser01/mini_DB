#include<iostream>
#include"Structure.h"
using namespace std;

datachunk::datachunk(){
    valid = 0;
    nI = nD = nS = 0;
    memset(Int, 0, sizeof(Int));
    memset(Double, 0, sizeof(Double));
    memset(String, 0, sizeof(String));
    next = nullptr;
}

datachunk* data_insert(datachunk* list, datachunk& input) {
	datachunk* first_node = list;
	if (list == nullptr) {
		//cout << "null" << endl;
		list = new datachunk;
        *list = input;
		list->next = nullptr;
		return list;
	}
	while (first_node->next != nullptr) {
		first_node = first_node->next;
	}
	datachunk* second_node = new datachunk;
	first_node->next = second_node;
    *second_node = input;
	second_node->next = nullptr;
	return list;
}
int data_size(datachunk* list) {
	datachunk* first_node = list;
	int number = 0;
	while (first_node != nullptr) {
		first_node = first_node->next;
		number++;
	}
	return number;
}
datachunk* data_search(datachunk* list, int number) {
	datachunk* first_node = list;
	for (int i = 0; i < number && first_node != nullptr; i++) {
		first_node = first_node->next;
	}
	if (first_node == nullptr) {
		return nullptr;
	}
	else {
		return first_node;
	}
}

datachunk_manager* datachunk_insert(datachunk_manager* list, datachunk* data){
	datachunk_manager* first_node = list;
	if (list == nullptr) {
		//cout << "null" << endl;
		list = new datachunk_manager;
		list->position = data;
		list->next = nullptr;
		return list;
	}
	while (first_node->next != nullptr) {
		first_node = first_node->next;
	}
	datachunk_manager* second_node = new datachunk_manager;
	first_node->next = second_node;
	second_node->position = data;
	second_node->next = nullptr;
	return list;
}

int datachunk_size(datachunk_manager* list) {
	datachunk_manager* first_node = list;
	int number = 0;
	while (first_node != nullptr) {
		first_node = first_node->next;
		number++;
	}
	return number;
}

datachunk* datachunk_search(datachunk_manager* list, int number) {
	datachunk_manager* first_node = list;
	for (int i = 0; i < number && first_node != nullptr; i++) {
		first_node = first_node->next;
	}
	if (first_node == nullptr) {
		return nullptr;
	}
	else {
		return first_node->position;
	}
}

structure::structure(){
    pposition = nullptr;
    line1 = 0;
    line2 = 0;
    memset(line3, 0 , sizeof(line3));
}

void structure::operator = (structure second) {
	this->pposition = second.pposition;
	this->line1 = second.line1;
	this->line2 = second.line2;
	for (int i = 0; i < 100; i++) {
		this->line3[i] = second.line3[i];
	}
}

bool structure::larger_than_second(structure second, int type) {
	if (type == 1) {
		if (line1 > second.line1) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (type == 2) {
		if (line2 > second.line2) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (type == 3) {
		for (int i = 0; i < 100; i++){
			if (line3[i] > second.line3[i]) {
				return true;
			}
            if (line3[i] < second.line3[i]){
                return false;
            }
		}
		return false;
	}
    return false;
}

bool structure::smaller_than_second(structure second, int type) {
	if (type == 1) {
		if (line1 < second.line1) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (type == 2) {
		if (line2 < second.line2) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (type == 3) {
		for (int i = 0; i < 100; i++) {
			if (line3[i] < second.line3[i]) {
				return true;
			}
            if (line3[i] > second.line3[i]){
                return false;
            }
		}
		return false;
	}
    return false;
}

bool structure::same_to_second(structure second, int type) {
	if (type == 1) {
		if (line1 == second.line1) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (type == 2) {
		if (line2 == second.line2) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (type == 3) {
		for (int i = 0; i < 100; i++) {
			if (line3[i] != second.line3[i]) {
				return false;
			}
		}
		return true;
	}
    return false;
}

void structure::clear() {
	//position = 0;
	pposition = nullptr;
	line1 = 0;
	line2 = 0;
	for (int i = 0; i < 100; i++) {
		line3[i] = 0;
	}
}
