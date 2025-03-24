
            #!/bin/bash
            clear  # Clear the terminal screen at the start
            cd "d:\cpp\nasledstvo_clion"
            if [ -f main ]; then
                rm main  # Remove the old binary if it exists
            fi
            g++ -o main main.cpp
            if [ $? -eq 0 ]; then
                ./main
            else
                echo "Compilation failed."
            fi
            echo ""  # Add a newline for better separation
            rm "d:\cpp\nasledstvo_clion\.main_run.sh"
        