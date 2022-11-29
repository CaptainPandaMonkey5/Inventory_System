#pragma once

// true OK, false bad
bool readUsers(Users& users)
{
	ifstream ifs(userfile);

	if (!ifs)
		return false;

	for (string line; getline(ifs, line); ) {
		UserData user;
		string id;
		istringstream iss(line);

		getline(iss, id, ',');
		getline(iss, user.name, ',');
		getline(iss, user.curpass, ',');

		const bool ok {iss};

		for (string pass; getline(iss, pass, ','); user.prevpass.insert(pass));

		// Assume data on file is correct - no duplicates etc
		if (ok)
			users[id] = user;
	}

	return true;
}