/*
 * Copyright (c) 2020 LcfTrans authors
 * This file is released under the MIT License
 * http://opensource.org/licenses/MIT
 */

#ifndef LCFTRANS_TRANSLATION
#define LCFTRANS_TRANSLATION

#include <string>
#include <vector>

#include "entry.h"

struct TranslationLdb;

class Translation
{
public:
	void write(std::ostream& out);

	void writeHeader(std::ostream& out) const;

	void writeEntries(std::ostream& out);

	bool addEntry(const Entry& entry);

	const std::vector<Entry>& getEntries() const;

	Translation Merge(const Translation& from);

	/**
	 * Takes the msgids of from and attempts to match them against msgid of
	 * this. When matched the msgid of from is copied to msgstr of this.
	 * @param from Translation to match from
	 * @param matched Number of matches
	 * @return Entries that failed to match
	 */
	Translation Match(const Translation& from, int& matches);

	static TranslationLdb fromLDB(const std::string& filename, const std::string& encoding);
	static Translation fromLMT(const std::string& filename, const std::string& encoding);
	static Translation fromLMU(const std::string& filename, const std::string& encoding);
	static Translation fromPO(const std::string& filename);

private:
	std::vector<Entry> entries;
};

struct TranslationLdb {
	Translation terms;
	Translation common_events;
	Translation battle_events;
};

#endif
