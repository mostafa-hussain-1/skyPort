#include <string>
#include "include/add_plane.h"
#include "DataStructures/skyport_array.h"
#include "include/search_planes.h"
using namespace std;


skyPort_array<int> plane_search_result;

//////////function search code///////
void search_by_code(string query)
{
    int qlen = query.length();

    for (int i = 0; i < planes.size(); ++i)
    {
        string target = planes[i].code;
        int lens = target.length();

        if (qlen > lens) continue;
        
        for (int j = 0; j <= lens - qlen; ++j)
        {
            if (target.substr(j, qlen) == query)
            {
				plane_search_result.push_back(i);
                break;
            }
        }
    }
}
//////////function search model///////

void searchByModel(string query) {
    
    int qLen = query.length();

    for (int i = 0; i < planes.size(); ++i)
    {
        string target = planes[i].model;
        int tLen = target.length();

        if (qLen > tLen) continue;

        for (int j = 0; j <= tLen - qLen; ++j)
        {
            if (target.substr(j, qLen) == query)
            {
                plane_search_result.push_back(i);
                break;
            }
        }
    }
}
