#pragma once

//true OK, false bad
Passerr checkPass(const UserData& user, const std::string& pass)
{
	// INCLUDE HERE OTHER REQUIRED TESTS FOR VALID PASSWORD

	size_t lowerCount {}, upperCount {};

	for (const auto& ch : pass) {
		upperCount += isupper(static_cast<unsigned char>(ch));
		lowerCount += islower(static_cast<unsigned char>(ch));
	}

	if (pass.size() < 6)
		return LENGTH;

	if (lowerCount == 0)
		return LOWER;

	if (upperCount == 0)
		return UPPER;

	if ((pass == user.curpass) || user.prevpass.count(pass))
		return DUPLICATE;

	return OK;
}