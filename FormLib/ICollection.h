#pragma once
namespace System {
	namespace Collection {
		template<typename T> class ICollection {
		public:
			virtual void Add(T value) = 0;
			virtual T Get(int index) = 0;
			virtual void Set(int index, T value) = 0;
			virtual int Size() = 0;
			virtual void Remove(T value) = 0;
			virtual void Clear() = 0;
			virtual T& operator[](int index) = 0;
			virtual void CopyTo(ICollection<T>& collection) = 0;
		};
	}
}