#include "crow_all.h"

int main()
{
    crow::SimpleApp app;

    //define your endpoint at the root directory
    CROW_ROUTE(app, "/")([]() {
        crow::mustache::set_base("html");
        auto html = crow::mustache::load_text("index.html");
        auto css = crow::mustache::load_text("css/style.css");
        html += "<style>" + std::string(css) + "</style>";
        return html;
        });


    app.port(18080).multithreaded().run();
}