#pragma once

// true OK, false bad
bool changePass(Users& users)
{
	system("cls");
	if (const auto iditr {getUser(users)}; iditr == users.end()) {
		cout << "Id does not exist\n";
	} else {
		if (const auto pass {getPass(iditr->second)}; !pass.empty()) {
			iditr->second.prevpass.insert(iditr->second.curpass);
			iditr->second.curpass = pass;
			return true;
		}
	}

	return false;
}
