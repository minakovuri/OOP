#pragma once
#include "HtmlReplacer.h"

const char START_HTML_ENTITY_SYMBOL = '&';
const char END_HTML_ENTITY_SYMBOL = ';';

std::string HtmlEncode(const std::string& text);
std::string HtmlDecode(std::string& text);