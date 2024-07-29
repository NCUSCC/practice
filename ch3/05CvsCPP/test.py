import subprocess
import time

def compile_and_measure(program_name, language):
    if language == "c":
        compile_command = f"gcc -O3 {program_name}.c -o {program_name}"
    elif language == "cpp":
        compile_command = f"g++ -O3 {program_name}.cpp -o {program_name}"
    
    # Measure compile time
    compile_start = time.time()
    subprocess.run(compile_command, shell=True, check=True)
    compile_duration = time.time() - compile_start

    # Run the program and measure the execution time
    run_start = time.time()
    result = subprocess.run(f"./{program_name}", shell=True, check=True, capture_output=True, text=True)
    run_duration = time.time() - run_start

    return compile_duration, run_duration, result.stdout

def main():
    c_compile_time, c_run_time, c_output = compile_and_measure("matrix_multiply", "c")
    cpp_compile_time, cpp_run_time, cpp_output = compile_and_measure("matrix_multiply", "cpp")

    print("C Program:")
    print(f"Compile time: {c_compile_time:.4f} seconds")
    print(f"Run time: {c_run_time:.4f} seconds")
    print(c_output)

    print("C++ Program:")
    print(f"Compile time: {cpp_compile_time:.4f} seconds")
    print(f"Run time: {cpp_run_time:.4f} seconds")
    print(cpp_output)

if __name__ == "__main__":
    main()