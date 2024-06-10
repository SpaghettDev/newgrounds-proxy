#include <Geode/Geode.hpp>

#include <Geode/modify/CCHttpClient.hpp>

using namespace geode::prelude;

std::string str_replace(std::string haystack, std::string needle, std::string replacement)
{
	std::string input = std::string(haystack.c_str());
    std::string replace_word = needle; 
    std::string replace_by = replacement; 

    size_t pos = input.find(replace_word); 

    while (pos != std::string::npos)
    {
        input.replace(pos, replace_word.size(), replace_by); 

        pos = input.find(replace_word, pos + replace_by.size()); 
    }

	return input;
}

class $modify(extension::CCHttpClient)
{
    void send(CCHttpRequest* request)
    {
        auto new_request_url = std::string(request->getUrl());
        new_request_url = str_replace(new_request_url, "audio.ngfiles.com", "newgrounds.auby.pro");
        new_request_url = str_replace(new_request_url, "http://", "https://");

        request->setUrl(new_request_url.c_str());

        this->send(request);
    }
};
