#include <iostream>

template <class T> 


class IntIterator; 
template <class T> 
class IntCollection{
	protected:
		T* array;
		int size;
		int cont;

	public: 
		friend class IntIterator<T>;

		IntCollection(){
			size = 10;
			cont = 0;
			array = new T[size];
		}

		void add(T value){
			if (cont <= size){
				array[cont++] = value;
				return;
			}
			else{
				std::cout << "\nYa no hay espacio para agregar elementos" << endl;
			}
		}

		IntIterator<T>* getIterator();

		T at(int pos){
			return array[pos];
		}
};

template <class T> 
class IntIterator{
	protected:
		IntCollection<T> coll;
		int cont = 0;

	public:
		IntIterator(const IntCollection<T>& coll) : coll(coll){}
	
		bool hasNext(){
			if (cont < coll.cont)
				return true;
			return false;
		}

		T Next(){
			return coll.at(cont++);
		}
};

template <class T> 
IntIterator<T>* IntCollection<T>:: getIterator(){
	return new IntIterator<T>(*this);
}
int main(){
	
	IntCollection<int> col;
	col.add(4);
	col.add(2);
	col.add(6);
	col.add(8);
	col.add(7);
	
	IntIterator<int>* i = col.getIterator();
	while (i->hasNext()){
		std::cout<< i->Next()<<" ";
	
	}
	
	return 0;

}
