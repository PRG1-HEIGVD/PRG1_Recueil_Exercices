# try/catch

Indiquer ce que va afficher chacune des séquences d'instructions suivantes : 


1.
~~~cpp
int main() {
   
   try {
      throw 1;
   } catch (int e) {
      cout << "Dans catch (int) : valeur recue = " << e << endl;
      throw 2.0;
   } catch (double e) {
      cout << "Dans catch (double e) : valeur recue = " << e << endl;
   } catch (...) {
      cout << "Dans catch (...)" << endl;
   }
   cout << "Fin du programme" << endl;
   
   return EXIT_SUCCESS;
}
~~~
<details>
<summary>Solution</summary>

Dans catch (int) : valeur recue = 1
terminate called after throwing an instance of 'double'
 
This application has requested the Runtime to terminate it in an unusual way.
Please contact the application's support team for more information.

</details>

2.
~~~cpp
int main() {
   try {
      try {
         throw 1;
      } catch (int e) {
         cout << "Dans catch (int) : valeur recue = " << e << endl;
         throw 2.0;
      } catch (...) {
         cout << "Dans catch (...)" << endl;
      }
   } catch (double e) {
      cout << "Dans catch (double) : valeur recue = " << e << endl;
   }
   cout << "Fin du programme" << endl;
   
   return EXIT_SUCCESS;
}
~~~
<details>
<summary>Solution</summary>

Dans catch (int) : valeur recue = 1
Dans catch (double) : valeur recue = 2
Fin du programme

</details>

3.	
~~~cpp
void f() {
   throw 'A';
}

int main() {
   try {
      try {
         f();
      } catch (int) {
         cout << "Dans catch (int) 1" << endl;
         throw;
      } catch (...) {
         cout << "Dans catch (...) 1" << endl;
         throw 65;  
      }
   } catch (int&) {
      cout << "Dans catch (int&)" << endl;
   } catch (int) {
      cout << "Dans catch (int) 2" << endl;
   } catch (const int) {
      cout << "Dans catch (const int)" << endl;
   } catch (...) {
      cout << "Dans catch (...) 2" << endl;
   }
   
   cout << "Fin du programme" << endl;
   
   return EXIT_SUCCESS;
}
~~~
<details>
<summary>Solution</summary>

Dans catch (...) 1
Dans catch (int&)
Fin du programme

</details>

4. 
~~~cpp
void f() {
   throw std::out_of_range("oops");
}

int main() {
   try {
      try {
         f();
      } catch (runtime_error& e) {
         cout << "R : " << e.what() << endl;
         throw;
      } catch (exception e) {
         cout << "E1 : " << e.what() << endl;
         throw;
      }
   } catch (logic_error& e) {
      cout << "L : " << e.what() << endl;
   } catch (exception& e) {
      cout << "E2 : " << e.what() << endl;
   }
   
   cout << "Fin du programme" << endl;
}
~~~

Consultez la documentation de [`std::out_of_range`](https://en.cppreference.com/w/cpp/error/out_of_range)

<details>
<summary>Solution</summary>
E1 : std::exception
L : oops
Fin du programme
</details>
