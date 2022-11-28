#pragma once

// true OK, false bad
bool writeUsers(const Users& users)
{
	std::ofstream ofs(userfile);

	if (!ofs)
		return false;

	for (const auto& user : users) {
		ofs << user.first << ',' << user.second.name << ',' << user.second.curpass << ',';

		for (size_t pasno = 0; const auto & pass : user.second.prevpass)
			ofs << (pasno++ ? "," : "") << pass;

		ofs << '\n';
	}

	return true;
}
