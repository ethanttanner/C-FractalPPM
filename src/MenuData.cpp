#include "MenuData.h"
#include <iostream>


MenuData::MenuData() { }

void MenuData::addAction(const std::string& name, ActionFunctionType func, const std::string& description) {
    commands.push_back( name );
    commandAction[ name ] = func;
    commandDescription[ name ] = description;
}

const std::vector<std::string>& MenuData::getNames() const {
    return commands;
}

ActionFunctionType MenuData::getFunction(const std::string& name) {
    if ( commandAction.find( name ) != commandAction.end() )
        return commandAction[ name ];
    else
        return 0;
}

const std::string& MenuData::getDescription(const std::string& name) {
    static std::string empty = "";
    if ( commandDescription.find( name ) != commandDescription.end() )
        return commandDescription[ name ];
    else
        return empty;
}



