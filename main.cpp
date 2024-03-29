#include <iostream>
#include <exception>

#include "Token.h"
#include "Codegen.h"
#include "Scanner.h"
#include "Parser.h"

int main(int argc, char* argv[]) {
    if (argc == 1) {
       std::cout << "no arguments were specified \n";
       return 1;
    }
    try {
        Scanner scanner(argv[1]);
        auto tokens = scanner.scan();
        Token::TokenSpan sp(tokens);

        Parser parser;
        auto nodes = parser.program(sp);
        //auto ast = parser.stmt(sp);

        Codegen generator;
        generator.generate_intro(parser.locals_count());
        for (const auto& node: nodes) {
            if (!generator.generate(node))
                break;
        }
        generator.generate_outro();

        return 0;
    } catch (const std::exception& ex) {
        std::cout << ex.what();
        return 1;
    }
}
