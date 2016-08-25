//=======================================================================
// Copyright Baptiste Wicht 2013-2016.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//=======================================================================

#include <tlib/file.hpp>
#include <tlib/system.hpp>
#include <tlib/errors.hpp>
#include <tlib/print.hpp>
#include <tlib/flags.hpp>

int main(int argc, char* argv[]){
    if(argc == 1){
        tlib::print_line("Usage: rm file_path");
        return 1;
    }

    auto fd = tlib::open(argv[1]);

    if(fd.valid()){
        auto result = tlib::rm(argv[1]);

        if(result < 0){
            tlib::printf("rm: error: %s\n", std::error_message(-result));
        }

        tlib::close(*fd);
    } else {
        tlib::printf("rm: error: %s\n", std::error_message(fd.error()));
    }

    return 0;
}
