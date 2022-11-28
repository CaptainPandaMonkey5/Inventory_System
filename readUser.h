#pragma once

// true OK, false bad
bool readUsers(Users& users)
{
	std::ifstream ifs(userfile);

	if (!ifs)
		return false;

	for (std::string line; std::getline(ifs, line); ) {
		UserData user;
		std::string id;
		std::istringstream iss(line);

		std::getline(iss, id, ',');
		std::getline(iss, user.name, ',');
		std::getline(iss, user.curpass, ',');

		const bool ok {iss};

		for (std::string pass; std::getline(iss, pass, ','); user.prevpass.insert(pass));

		// Assume data on file is correct - no duplicates etc
		if (ok)
			users[id] = user;
	}

	return true;
}