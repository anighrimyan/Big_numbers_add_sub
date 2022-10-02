#include <iostream>
#include <string>

bool is_number(std::string& str);
void from_string_to_int(std::string &str, int* arr, int size);
int* create_int_array(int size);
void delete_array(int* arr);
int* add_big_data(int* arr_str_number1, int* arr_str_number2, int size);
int* sub_big_data(int* arr_str_number1, int* arr_str_number2, int size);
int* sub_big_data_2(int* arr_str_number1, int* arr_str_number2, int size);
void print (int* arr, int size);

int main() {
	std::string str_number1{};
	std::string str_number2{};
	std::cout << "Enter the numbers: " << std::endl;
	std::cout << "number1 = ";
	std::cin >> str_number1;
	std::cout << std::endl;
	std::cout << "number2 = ";
	std::cin >> str_number2;
	std::cout << std::endl;
	int size1 = str_number1.size() + 1;
	int size2 = str_number2.size() + 1;

  if (is_number(str_number1) && is_number(str_number2)) {
    if (size1 > size2) {
      int* arr_str_number1 = create_int_array(size1);
	    from_string_to_int(str_number1, arr_str_number1, size1);
      std::cout << "Big number first: \n";
      print(arr_str_number1, size1);
      int* arr_str_number2 = new int[size1];
	    from_string_to_int(str_number2, arr_str_number2, size1);
      std::cout << "Big number second: \n";
      print(arr_str_number2, size2);
      int* add_arr = add_big_data(arr_str_number1, arr_str_number2, size1); 
      std::cout << "Sum of two big numbers is: \n";
      print(add_arr, size1);
      int* sub_arr = sub_big_data(arr_str_number1, arr_str_number2, size1); 
      std::cout << "Sub of two big numbers is: \n";
      print(sub_arr, size1);
      delete_array(arr_str_number1);
      delete_array(arr_str_number2);
      delete_array(add_arr);
      delete_array(sub_arr);
  } 
  if (size1 < size2) {
    int* arr_str_number1 = create_int_array(size2);
	  from_string_to_int(str_number1, arr_str_number1, size2);
    print(arr_str_number1, size2);
    int* arr_str_number2 = new int[size2];
	  from_string_to_int(str_number2, arr_str_number2, size2);
    print(arr_str_number2, size2);
    int* add_arr = add_big_data(arr_str_number1, arr_str_number2, size2); 
    std::cout << "Sum of two big numbers is: \n";
    print(add_arr, size2);
    int* sub_arr = sub_big_data_2(arr_str_number1, arr_str_number2, size2); 
    std::cout << "Sub of two big numbers is: \n" << "-";
    print(sub_arr, size2);
    delete_array(arr_str_number1);
    delete_array(arr_str_number2);
    delete_array(add_arr);
    delete_array(sub_arr);
  }
  if (size1 == size2) {
    int* arr_str_number1 = create_int_array(size1);
	  from_string_to_int(str_number1, arr_str_number1, size1);
    print(arr_str_number1, size1);
    int* arr_str_number2 = new int[size1];
	  from_string_to_int(str_number2, arr_str_number2, size1);
    print(arr_str_number2, size1);
    int* add_arr = add_big_data(arr_str_number1, arr_str_number2, size1); 
    std::cout << "Sum of two big numbers is: \n";
    print(add_arr, size1);
    bool result = true;
    int i = 0;
      while (i < size1) {
        if (arr_str_number1[i] == arr_str_number2[i]) {
          ++i;
          result = true;
        } else if (arr_str_number1[i] > arr_str_number2[i]) {
          result = true;
          ++i;
        }else {
          result = false;
          ++i;
        }
     }
      if (!result) {
        int* sub_arr = sub_big_data_2(arr_str_number1, arr_str_number2, size1);
        std::cout << "Sub of two big numbers is: \n" << "-";
        print(sub_arr, size1);
        delete_array(sub_arr);
      } else {
        int* sub_arr = sub_big_data(arr_str_number1, arr_str_number2, size1);
        std::cout << "Sub of two big numbers is: \n";
        print(sub_arr, size1);
        delete_array(sub_arr);
      }
    delete_array(arr_str_number1);
    delete_array(arr_str_number2);
    delete_array(add_arr);
  }
  }
 }

//This function print the result.
void print (int* arr, int size) {
  for (int i = 0; i < size; ++i) {
    std::cout << arr[i];
    }
  std::cout << std::endl;
}

//This function subtract two arrays./2/
  int* sub_big_data_2(int* arr_str_number1, int* arr_str_number2, int size) {
    int carry = 0;
    int* arr = new int[size];
    for (int k = size - 1; k >= 0; ) {
      for (int i = size - 1, j = size - 1; j >=0; --i, --j) {
       if (arr_str_number2[i] >= arr_str_number1[j]) {
         arr[k] = (arr_str_number2[i] - arr_str_number1[j]);
         --k;
       }else if (arr_str_number1[i] < arr_str_number2[j]) {
        carry = 10;
        arr_str_number2[i - 1] = arr_str_number2[i - 1] - 1;
        arr[k] = (arr_str_number2[i] + carry - arr_str_number1[j]);
        --k;
      } 
    }   
   }   
  return arr;
  }

//This function subtract two arrays.
int* sub_big_data(int* arr_str_number1, int* arr_str_number2, int size) {
  int carry = 0;
  int* arr = new int[size];
  for (int k = size - 1; k >= 0; ) {
    for (int i = size - 1, j = size - 1; j >=0; --i, --j) {
      if (arr_str_number1[i] >= arr_str_number2[j]) {
        arr[k] = (arr_str_number1[i] - arr_str_number2[j]);
        --k;
      } else if (arr_str_number1[i] < arr_str_number2[j]) {
        carry = 10;
        arr_str_number1[i - 1] =arr_str_number1[i - 1] - 1;
        arr[k] = (arr_str_number1[i] + carry - arr_str_number2[j]);
        --k;
     } 
    }   
  }
  return arr;
}

//This function addition two arrays.
int* add_big_data(int* arr_str_number1, int* arr_str_number2, int size) {
  int carry = 0;
  int* arr = new int[size];
  for (int k = size - 1; k >= 0; ) {
    for (int i = size - 1, j = size - 1; j >=0; --i, --j) {
      arr[k] = (arr_str_number1[i] + arr_str_number2[j] + carry) % 10;
      carry = (arr_str_number1[i] + arr_str_number2[j] + carry) / 10;
      --k;
   }  
  }
  return arr;
 } 

// This function convert the elements of string to int and assigned int array.
void from_string_to_int(std::string& str, int* arr, int size) {
  int j = size - 1;
  for (int i = str.size() - 1; i >= 0 ; --i) {
     arr[j] = str[i] - '0';
     --j;
   }
}

// This function create int array
int* create_int_array(int size) {
	int* arr = new int[size];
  for (int i = 0; i < size; ++i) {
    arr[i] = 0;
  }
	return arr;
}

//This function check the strings elements are number or not.
bool is_number(std::string& str) {
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] < '0' && str[i] > '9') {
			return false;
		}
	}
	return true;
}

//This function delete dynamic array
void delete_array(int* arr) {
	delete[] arr;
	arr = nullptr;
}