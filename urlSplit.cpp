#include <bits/stdc++.h>
using namespace std;

int main()
{
    string url = "https://google.com:3000/home";
    string protocol, domain, port = "None", path = "/";
    int pos = url.find("://");
    if (pos != -1)
    {
        protocol = url.substr(0, pos);
        pos += 3;
    }
    else
    {
        protocol = "unknown";
        pos = 0;
    }

    int domainend = url.find_first_of(":/", pos);
    if (domainend != -1)
    {
        domain = url.substr(pos, domainend - pos);
    }

    if (domainend != -1 && url[domainend] == ':')
    {
        int portEnd = url.find("/", domainend + 1);
        port = url.substr(domainend + 1, portEnd - domainend - 1);
        domainend = portEnd;
    }

    if (domainend != -1)
    {
        path = url.substr(domainend);
    }

    cout << "Protocol: " << protocol << endl;
    cout << "Domain: " << domain << endl;
    cout << "Port: " << port << endl;
    cout << "Path: " << path << endl;
    return 0;
}