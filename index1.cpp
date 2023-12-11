#include "crow_all.h"

int main()
{
    crow::SimpleApp app;

    //define your endpoint at the root directory
    CROW_ROUTE(app, "/")([]() {
        crow::mustache::set_base("html");
        auto head = crow::mustache::load_text("header.html");
        auto page = crow::mustache::load_text("index.html");
        auto css = crow::mustache::load_text("style.css");
        //html += "<style>" + std::string(css) + "</style>";
        //return page;
        return head.append(css).append(page);
        });


    app.port(18080).multithreaded().run();
}