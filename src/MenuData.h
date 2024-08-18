#ifndef _MENUDATA_H_
#define _MENUDATA_H_

#include <map>
#include <string>
#include "PPM.h"
#include "Image.h"
#include "ActionData.h"
#include <vector>

typedef void (*ActionFunctionType)(ActionData& action_data);

class MenuData {
public:
    MenuData();
    void addAction(const std::string& name, ActionFunctionType func, const std::string& description);
    const std::vector<std::string>& getNames() const;
    ActionFunctionType getFunction(const std::string& name);
    const std::string& getDescription(const std::string& name);

private:
    std::vector<std::string> commands;
    std::map<std::string,ActionFunctionType> commandAction;
    std::map<std::string,std::string> commandDescription;
};

#endif // _MENUDATA_H_

