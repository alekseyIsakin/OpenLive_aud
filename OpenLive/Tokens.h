#pragma once

#include "nlohmann/json.hpp"

#define EMPTY_TOKEN ""
#define RSI_URL _T("https://secure.rsi.exchange:3222/get_tokens_by_uuid_keyvalue?uuid_=")

class langHolder {
public:
	std::string langShort;
	std::string langFull;
	std::string token;
};

class Tokens
{
protected:
	CString _hostToken;
	CString _hostName;
	
	std::vector<langHolder> _listShortLang;

	// from ROOMS_NAMES_TARGET
	void setLang(nlohmann::json langsJson);
public:
	Tokens();
	BOOL GetCloudToken(CString roomNumber);

	std::string GetToken(int id);
	CString GetName(int id);

	std::string GetHostToken();
	CString GetHostName();

	BOOL isEmptyToken();

	std::vector<langHolder>::iterator GetLngBgnIterator();
	std::vector<langHolder>::iterator GetLngEndIterator();
};

