template<class T>
using class_method_ptr = size_t(T::*)() const;
template<class T>
using class_field_ptr = size_t T::*;

template<class T, class_method_ptr<T> = &T::size>
size_t get_size(const T& value){
	return value.size();
}

template<class T, class_field_ptr<T> = &T::size>
size_t get_size(const T& value) {
	return value.size;
}
