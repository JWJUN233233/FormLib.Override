#pragma once
#include "IList.h"
#include "QuickProperty.h"
namespace System {
	namespace Method {
		template <typename T>int Count_OnGet(Util::QuickProperty<int>& property);
		template <typename T>void Count_OnSet(Util::QuickProperty<int>& property, int value);
	}
	namespace Collection {
		template <typename T> class LinkedList : public IList<T>
		{
		public:
			Util::QuickProperty<int> Count{ 0, true };
			inline LinkedList() {
				Count.SetOwner(this);
				Count.OnGet = Method::Count_OnGet<T>;
				Count.OnSet = Method::Count_OnSet<T>;
			}
			inline ~LinkedList()
			{
				if (!IsEmpty()) {
					delete FirstNode;
				}
			}
			inline virtual void Add(T value) {
				if (!IsEmpty()) {
					LinkedNode<T>* newNode = new LinkedNode<T>(value);
					EndNode->NextNode = newNode;
					EndNode = EndNode->NextNode;
				}
				else {
					FirstNode = new LinkedNode<T>(value);
					EndNode = FirstNode;
				}
			}
			inline virtual T Get(int index) {
				return GetPtr(index);
			}
			inline virtual T& GetPtr(int index) {
				if (IsEmpty()) {

				}
				LinkedNode<T>* nodeptr = FirstNode;
				for (int i = 0; i < index + 1; i++) {
					nodeptr = nodeptr->NextNode;
					if (i == index) {
						return nodeptr->Value;
					}
				}
			}
			inline virtual void Set(int index, T value) {
				int i = 0;
				LinkedNode<T>* node = FirstNode;
				while (true) {
					if (node == nullptr) {
						break;
					}
					else if (i == index) {
						node->Value = value;
						break;
					}
					else {
						i++;
						node = node->NextNode;
					}
				}
			}
			inline virtual int Size() {
				if (IsEmpty()) {
					return 0;
				}
				LinkedNode<T>* nodeptr = FirstNode;
				int size = 0;
				while (true) {
					size++;
					nodeptr = nodeptr->NextNode;
					if (nodeptr == nullptr) {
						return size;
					}
				}
			}
			inline virtual void Remove(T value) {

			}
			inline virtual void Clear() {
				delete FirstNode;
				FirstNode = nullptr;
				EndNode = nullptr;
			}
			inline bool IsEmpty() {
				return FirstNode == nullptr;
			}
		private:
			template <typename T>class LinkedNode
			{
			public:
				LinkedNode<T>* NextNode = nullptr;
				T Value;
				LinkedNode(T value) {
					Value = value;
				}
				~LinkedNode()
				{
					if (NextNode != nullptr) {
						delete NextNode;
					}
				}
			};
			LinkedNode<T>* FirstNode = nullptr;
			LinkedNode<T>* EndNode = nullptr;
		};
	}
	namespace Method {
		template <typename T>int Count_OnGet(Util::QuickProperty<int>& property) {
			void* ptr = property.GetOwner();
			return ((Collection::LinkedList<T>*)ptr)->Size();
		}
		int Count_OnGet_test(Util::QuickProperty<int>& property) {
			void* ptr = property.GetOwner();
			return ((Collection::LinkedList<int>*)ptr)->Size();
		}
		template <typename T>void Count_OnSet(Util::QuickProperty<int>& property, int value) { }
	}

}