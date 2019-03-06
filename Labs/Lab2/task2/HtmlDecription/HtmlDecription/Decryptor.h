#pragma once
#include "HtmlReplacer.h"

const char START_HTML_ENTITY_SYMBOL = '&';
const char END_HTML_ENTITY_SYMBOL = ';';

std::string HtmlEncode(std::string const& text);
std::string HtmlDecode(std::string& text);