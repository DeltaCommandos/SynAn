#include "Checking.h"


void Checking::bracketCheck() {
	int brackets[4] = { };
	int comment = 0;
	int checkCR = 0,checkFR = 0;
	for (string count : ArrNoSpace) {

		if (count == "//"){
			comment = 1;
		}
		if (count == "\n") {
			comment = 0;
		}
		if (comment == 1) {
			continue;
		}


		if (count == "(") 
			brackets[0]++;
		
		if (count == ")") {
			brackets[1]++;
			if (brackets[0] - brackets[1] < 0) {
				checkCR++;
			}
		}

		if (count == "{")
			brackets[2]++;

		if (count == "}") {
			brackets[3]++;
			if (brackets[2] - brackets[3] < 0) {
				checkFR++;
			}
		}
	}
	
	if ((brackets[0] != brackets[1])||(checkCR!=0)) {
		ErrBr.StrNum.push_back(abs(brackets[0] - brackets[1])+checkCR);
		ErrBr.Description.push_back(" круглых(-ой) скобок(-и)!");
	}
	if ((brackets[2] != brackets[3]) || (checkFR != 0)) {
		ErrBr.StrNum.push_back(abs(brackets[2] - brackets[3])+checkFR);
		ErrBr.Description.push_back(" фигурных(-ой) скобок(-и)!");
	}
}

void Checking::conBreCheck(int a) {

	/*int p1 = 0, p2 = 0;
	int br1 = 0, br2 = 0;
	int brFlag = 0, i = 0, comment = 0;

	vector <int> bracketpos{};
	string elem;

	int lines = 1;
	for (string q : ArrNoSpace) {

		if (q == "//")
			comment = 1;
		if (q == "\n") {
			comment = 0;
		}
		if(comment==1)
			continue;

		if ((q == "for") || (q == "while")) {
			if (i == N)
				break;
			if (ArrNoSpace[i + 1] == "(") {
				int t1 = i + 2;
				for (t1; t1 < N; t1++) {
					if (ArrNoSpace[t1] == "(") {
						br1++;
					}
					if (ArrNoSpace[t1] == ")") {
						if (br1 != 0) {
							br1--;
						}
						else {
							if (ArrNoSpace[t1 + 1] != "{") {
								ErrOnlyStr.push_back("Нет тела цикла");
								break;
							}
							else {
								int p1 = t1 + 1, p = t1 + 2;
								while (p < N) {
									if (ArrNoSpace[p] == "{") {
										br2++;
									}
									if (ArrNoSpace[p] == "}") {
										if (br2 != 0) {
											br2--;
										}
										else {
											brFlag = 1;
											p2 = p;
											bracketpos.push_back(p1);
											bracketpos.push_back(p2);
											p1 = 0;
											p2 = 0;
											break;
										}
									}
									p++;
								}
								if (brFlag == 0) {
									bracketpos.push_back(0);
									bracketpos.push_back(0);
								}
								p1 = 0;
								p2 = 0;
								break;
							}
						}
					}
				}
			}
			else
			{
				ErrOnlyStr.push_back("Нет круглой скобки в цикле");
			}
		}

		i++;
	}
	for (int i = 0; i < N; i++) {
		int lastlastflag = 0;
		if (ArrNoSpace[i] == "\n")
			lines++;
		if (ArrNoSpace[i] == "continue") {
			for (int j = 0; j < bracketpos.size(); j = j + 2) {
				if ((i > bracketpos[j]) && (i < bracketpos[j + 1])) {
					lastlastflag = 1;
				}
			}
			if ((!lastlastflag)&&(a == 8)){
					ErrStrAndNum.StrNum.push_back(lines);
					ErrStrAndNum.Description.push_back(" continue расположен неправильно!");
				}
			}
		if (ArrNoSpace[i] == "break") {
			for (int j = 0; j < bracketpos.size(); j = j + 2) {
				if ((i > bracketpos[j]) && (i < bracketpos[j + 1])) {
					lastlastflag = 1;
				}
			}
			if ((!lastlastflag) && (a == 9)) {
					ErrStrAndNum.StrNum.push_back(lines);
					ErrStrAndNum.Description.push_back(" break расположен неправильно!");
				}
			}
		}*/

	int p1 = 0, p2 = 0;
	int br1 = 0, br2 = 0;
	int doWhileFlag = 1;
	int brFlag = 0, i = 0, comment = 0;
	vector <int> bracketpos{};
	string elem;
	int lines = 1;

	for (string q : ArrNoSpace) {

		if (q == "//")
			comment = 1;
		if (q == "\n") {
			comment = 0;
		}
		if (comment == 1)
			continue;

		if (i == N)
			break;
		if ((q == "for") || ((q == "while") && (doWhileFlag == 1))) {
			if (ArrNoSpace[i + 1] == "(") {
				int t1 = i + 2;
				for (t1; t1 < N; t1++) {
					if (ArrNoSpace[t1] == "(") { //
						br1++;
					}
					if (ArrNoSpace[t1] == ")") {
						if (br1 != 0) {
							br1--;
						}
						else {
							if (ArrNoSpace[t1 + 1] != "{") {
								int lineInBracket = t1 + 1;
								while (lineInBracket < N) {
									if ((ArrNoSpace[lineInBracket] == "\n")) {
										continue;
									}
									if ((ArrNoSpace[lineInBracket] == "break") || (ArrNoSpace[lineInBracket] == "continue")) {
										bracketpos.push_back(t1);
										bracketpos.push_back(t1 + 2);
										break;
									}
									else
										break;
									lineInBracket++;
								}
								break;
							}
							else {
								int p1 = t1 + 1, p = t1 + 2;
								while (p < N) {
									if (ArrNoSpace[p] == "{") {
										br2++;
									}
									if (ArrNoSpace[p] == "}") {
										if (br2 != 0) {
											br2--;
										}
										else {
											brFlag = 1;
											p2 = p;
											bracketpos.push_back(p1);
											bracketpos.push_back(p2);
											p1 = 0;
											p2 = 0;
											break;
										}
									}
									p++;
								}
								if (brFlag == 0) {
									bracketpos.push_back(0);
									bracketpos.push_back(0);
								}
								p1 = 0;
								p2 = 0;
								break;
							}
						}
					}
				}
			}
			else
			{
				ErrOnlyStr.push_back("Нет круглой скобки в цикле");
			}
		}
		else {
			if ((q == "while") && (doWhileFlag == 0)) {
				doWhileFlag = 1;
			}
			if (q == "do") {
				int t1 = i;
				for (t1; t1 < N; t1++) {
					if (ArrNoSpace[t1 + 1] != "{") {
						int lineInBracket = t1 + 1;
						int doWhileEndFlag = 0;
						while (lineInBracket < N) {
							if ((ArrNoSpace[lineInBracket] == "\n")) {
								lineInBracket++;
								continue;
							}

							if ((ArrNoSpace[lineInBracket] == "break") || (ArrNoSpace[lineInBracket] == "continue")) {
								int NextLinBr = lineInBracket + 1;
								while (NextLinBr < N) {
									if (ArrNoSpace[NextLinBr + 1] == "\n") {
										NextLinBr++;
										continue;
									}
									else {
										if (ArrNoSpace[NextLinBr + 1] == "while") {
											if (ArrNoSpace[NextLinBr + 2] == "(") {
												int t2 = NextLinBr + 3;
												for (t2; t2 < N; t2++) {
													if (ArrNoSpace[t2] == "(") { //
														br1++;
													}
													if (ArrNoSpace[t2] == ")") {
														if (br1 != 0) {
															br1--;
														}
														else {
															if (ArrNoSpace[t2 + 1] == ";") {
																brFlag = 1;
																p2 = NextLinBr;
																bracketpos.push_back(p1);
																bracketpos.push_back(p2);
																p1 = 0;
																p2 = 0;
																doWhileFlag = 0;
																doWhileEndFlag = 1;
																break;
															}
															else

																break;
														}
													}
												}
											}
										}
										else
											break;
										NextLinBr++;
									}
									if (doWhileEndFlag)
										break;
								}

							}
							if (doWhileEndFlag)
								break;
							lineInBracket++;
						}
					}
					else {
						int p1 = t1 + 1, p = t1 + 2;
						int doWhileEndFlag = 0;
						while (p < N) {
							if (ArrNoSpace[p] == "{") {
								br2++;
							}
							if (ArrNoSpace[p] == "}") {
								if (br2 != 0) {
									br2--;
								}
								else {
									int NextLinBr = p;
									while (NextLinBr < N) {
										if (ArrNoSpace[NextLinBr + 1] == "\n") {
											NextLinBr++;
											continue;
										}
										else {
											if (ArrNoSpace[NextLinBr + 1] == "while") {
												if (ArrNoSpace[NextLinBr + 2] == "(") {
													int t2 = NextLinBr + 3;
													for (t2; t2 < N; t2++) {
														if (ArrNoSpace[t2] == "(") { //
															br1++;
														}
														if (ArrNoSpace[t2] == ")") {
															if (br1 != 0) {
																br1--;
															}
															else {
																if (ArrNoSpace[t2 + 1] == ";") {
																	brFlag = 1;
																	p2 = NextLinBr;
																	bracketpos.push_back(p1);
																	bracketpos.push_back(p2);
																	p1 = 0;
																	p2 = 0;
																	doWhileFlag = 0;
																	doWhileEndFlag = 1;
																	break;
																}
																else
																	break;
															}
														}
													}
												}
											}
											else
												break;
											NextLinBr++;
										}
										if (doWhileEndFlag)
											break;
									}
								}

							}
							if (doWhileEndFlag)
								break;
							p++;
						}
						if (brFlag == 0) {
							bracketpos.push_back(0);
							bracketpos.push_back(0);
						}
						p1 = 0;
						p2 = 0;
						break;
					}
				}
			}
		}
		i++;
	}
	for (int i = 0; i < N; i++) {
		int lastlastflag = 0;
		if (ArrNoSpace[i] == "\n")
			lines++;
		if (ArrNoSpace[i] == "continue") {
			for (int j = 0; j < bracketpos.size(); j = j + 2) {
				if ((i > bracketpos[j]) && (i < bracketpos[j + 1])) {
					lastlastflag = 1;
				}
			}
			if ((!lastlastflag) && (a == 8)) {
				ErrStrAndNum.StrNum.push_back(lines);
				ErrStrAndNum.Description.push_back(" continue расположен неправильно!");
			}
		}
		if (ArrNoSpace[i] == "break") {
			for (int j = 0; j < bracketpos.size(); j = j + 2) {
				if ((i > bracketpos[j]) && (i < bracketpos[j + 1])) {
					lastlastflag = 1;
				}
			}
			if ((!lastlastflag) && (a == 9)) {
				ErrStrAndNum.StrNum.push_back(lines);
				ErrStrAndNum.Description.push_back(" break расположен неправильно!");
			}
		}
	}
}


void Checking::IniCheck() {

	vector <string> namesint{};
	int comment = 0;
	int lines = 1;
	int isvar = 0;
	for (auto var : Vars) {
		for (int i = 0; i < N; i++) {
			string elem = ArrNoSpace[i];
			if (elem == "//")
				comment = 1;
			if (elem == "\n")
				comment = 0;
			if (comment == 1)
				continue;
			if (elem == var) {
				if (ArrNoSpace[i + 1] == "main")
					continue;
				
				isvar++;
				continue;
			}
			if (isvar != 0) {
				string varName;
				bool isEqual = 0;
				for (int j = i; (ArrNoSpace[j-1]=="=")||(ArrNoSpace[j] == "\n"); j++) {
					if (ArrNoSpace[j] == "=") {
						isEqual = 1;
					}
					varName.append(ArrNoSpace[j]);

				}
				IniList.Type.push_back(var);
				IniList.Name.push_back(varName);
				if (isdigit(varName[0])) {
					ErrStrAndNum.StrNum.push_back(lines);
					ErrStrAndNum.Description.push_back(" недопустимое название переменной!");
				}

				if (isEqual) {
					string varData;
					bool isPointComma = 0;
					for (int j = i; (ArrNoSpace[j - 1] == ";") || (ArrNoSpace[j] == "\n"); j++) {
						if ((ArrNoSpace[j] == ";")||(ArrNoSpace[j] == ",")) {
							isPointComma = 1;
						}
						varData.append(ArrNoSpace[j]);
					}
					IniList.Data.push_back(varData);
					if (!isPointComma) {
						ErrStrAndNum.StrNum.push_back(lines);
						ErrStrAndNum.Description.push_back(" требуется точка с запятой ';'!");

					}
					cout << "\n" << varData;
				}
				cout << "\n" << var;
				cout << "\n" << varName;


			}
			
		}
	}

	//for (int i = 0; i < N; i++) {
	//	int lines = 1;
	//	int l = 0;
	//	if (ArrNoSpace[i] == "\n") {
	//		lines++;
	//		break;
	//	}
	//	if (ArrNoSpace[i] == "int") {
	//		if (ArrNoSpace[i + 1] == "main")
	//			continue;
	//		for (string k : namesint) {
	//			if ((ArrNoSpace[i + 1]) == k) {
	//				ErrStrAndNum.StrNum.push_back(lines);
	//				ErrStrAndNum.Description.push_back(" неправильно инициализированна(-ы) переменная(-е)!");
	//				break;
	//			}
	//		}
	//		int symbolcheck = 1;
	//		if (!isalpha(ArrNoSpace[i + 1][0])) {
	//			symbolcheck = 0;
	//		}
	//		if (symbolcheck) {
	//			namesint.push_back(ArrNoSpace[i + 1]);
	//		}
	//		else {
	//			ErrStrAndNum.StrNum.push_back(lines);
	//			ErrStrAndNum.Description.push_back(" недопустимое название переменной!");
	//			break;
	//		}
	//		int j = i + 1;
	//		int strl = 0;
	//		while ((ArrNoSpace[j] != "\n") && !(strl == N)) {
	//			if (ArrNoSpace[j] == ",") {
	//				if (ArrNoSpace[j + 1] != "int") {
	//					for (string k : namesint) {
	//						if ((ArrNoSpace[j + 1]) == k) {
	//							cout << "\nВ строке " << lines << "неправильно инициализированна(-ы) переменная(-е)!" << endl;
	//							break;
	//						}
	//					}
	//					int symbolcheck = 1;
	//					if (!isalpha(ArrNoSpace[j + 1][0])) {
	//						symbolcheck = 0;
	//					}
	//					if (symbolcheck) {
	//						namesint.push_back(ArrNoSpace[j + 1]);
	//					}
	//					else {
	//						cout << "\nВ строке " << lines << " недопустимое название переменной!" << endl;
	//						break;
	//					}
	//					if (ArrNoSpace[j + 2] == "=") {
	//						;
	//					}
	//				}
	//				else {
	//					cout << "\nВ строке " << lines << "неправильно инициализированна(-ы) переменная(-е)!" << endl;
	//					break;
	//				}
	//			}
	//			else {
	//				int y = j;
	//				bool jb = 0;//ôëàã
	//				int prada = 1;
	//				if (ArrNoSpace[y] == "=") {
	//					while ((ArrNoSpace[y] != "\n") && !(strl == N))
	//					{
	//						if ((ArrNoSpace[y] == "(") || (ArrNoSpace[y] == ")")) {
	//							y++;
	//							continue;
	//						}
	//						for (string el : namesint) {
	//							if (ArrNoSpace[y] == el) {
	//								jb = 1;
	//								continue;
	//							}
	//						}
	//						for (int q = 0; q < ArrNoSpace[i].size(); q++) {
	//							if (!isalpha(ArrNoSpace[i][q])) {
	//								prada = 0;
	//								break;
	//							}
	//						}
	//					}
	//				}
	//				if (!prada) {
	//					cout << "\nÁåç èíâàéòà";
	//				}
	//			}
	//			j++;
	//			strl++;
	//		}
	//		i = j;
	//		lines++;
	//	}
	//	int flag = 0;
	//	if (ArrNoSpace[i] == "=") {
	//		for (string k : namesint) {
	//			if ((ArrNoSpace[i - 1]) == k) {
	//				flag = 1;
	//				break;
	//			}
	//		}
	//		if (!flag) {

	//			ErrStrAndNum.StrNum.push_back(lines);
	//			ErrStrAndNum.Description.push_back(" неправильно инициализированна(-ы) переменная(-е)!");

	//		}
	//	}

	//	//if (correctvar) {
	//	//	variable var;
	//	//	var.name = words[i + 1];
	//	//	var.isInit = (words[i + 2] != ";");
	//	//}
	//}
}

void Checking::mainCheck() {

	int flag = 0, lines = 1, i = 0, pos = 0;
	string nextline = "\n";
	int c = 0, comment = 0;

	for (string k : ArrNoSpace) {
		if (ArrNoSpace[i] == "//")
			comment = 1;
		if (ArrNoSpace[i] == "\n")
			comment = 0;
		if (comment == 1)
			continue;

		if (k == "main") {
			for (string l : Vars) {
				if (ArrNoSpace[i - 1] == l) {
					flag = 1;
				}
			}
			c++;
		}
		i++;
	}
	if (!flag) {
		ErrOnlyStr.push_back("Отсутсвует точка входа");
	}
	switch (c) {
	case 0:
		ErrOnlyStr.push_back("Отсутсвует main");
	case 1:
		break;
	default:
		ErrOnlyStr.push_back("main: Функция не может быть перегружена");
	}
}

