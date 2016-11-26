#pragma once
#include "stdafx.h"
#include "resource.h"
#include "Classes\Multinomial.h"
#include <vector>

using namespace std;

vector<string> multToString(vector<Multinomial> multy)
{
	vector<string> strings;
	for (int i = 0; i < multy.size(); ++i) {
		strings.push_back(multy[i].getToString());
	}
	return strings;
}

bool findMulty(vector<Multinomial> multy, Multinomial multyresult)
{
	bool tmp = 0;
	string multystring = multyresult.getToString();
	vector<string> multystrings = multToString(multy);
	for (int i = 0; i < multy.size(); ++i) {
		if (multystring == multystrings[i])
			tmp = 1;
	}
	return tmp;
}

void addToVector(vector<Multinomial> multy, Multinomial plusresult, HWND editresult1, HWND combo1, HWND combo2)
{
	bool p = findMulty(multy, plusresult);
	if (p == 0)		multy.push_back(plusresult);
	SendMessageA(editresult1, WM_SETTEXT, NULL, (LPARAM)(plusresult.getToString().c_str()));
	SendMessageA(combo1, CB_RESETCONTENT, 0, 0);
	SendMessageA(combo2, CB_RESETCONTENT, 0, 0);
	vector<string> multystring = multToString(multy);
	if (multystring.empty() != true) {
		for (int i = 0; i <= multystring.size() - 1; i++) {
			SendMessageA(combo1, CB_ADDSTRING, 0, (LPARAM)multystring[i].c_str());
			SendMessageA(combo2, CB_ADDSTRING, 0, (LPARAM)multystring[i].c_str());
		}
	}
}
