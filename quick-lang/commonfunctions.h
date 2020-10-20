#pragma once

std::vector<std::string> SplitString(std::string stringToSplit, char splitChar) { // a split function so I can use, this is very convenient.
	std::vector<std::string> result;

	std::string bufferString; // String builds until it reaches the char where it appends to the result vector and resets.
	for (size_t i = 0; i < stringToSplit.size(); i++)
	{
		if (stringToSplit[i] == splitChar) {
			result.push_back(bufferString);
			bufferString = "";
		}
		else {
			bufferString += stringToSplit[i];
		}
	}

	if (bufferString != "") {
		result.push_back(bufferString);
		
	}

	return result;
}

std::string CheckIfInVector(std::string value, std::vector<std::string> scanVector) {
	for (size_t i = 0; i < scanVector.size(); i++)
	{
		if (value == scanVector[i]) {
			return scanVector[i];
		}
	}
	return "";
}

void Error() { // I will make this close the translator

}