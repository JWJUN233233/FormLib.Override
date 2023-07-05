#pragma once
#include "Property.h"
namespace System {
	namespace Util {
		template <typename T> class QuickProperty : Property<T> {
		public:
			typedef T (*GetMethod)(QuickProperty<T>&);
			typedef void (*SetMethod)(QuickProperty<T>&, T);
			GetMethod OnGet = nullptr;
			SetMethod OnSet = nullptr;
			T Value;
			bool IsReadOnly = false;
			QuickProperty() {

			}
			QuickProperty(bool isReadOnly) {
				IsReadOnly = isReadOnly;
			}
			QuickProperty(T value) {
				Value = value;
			}
			QuickProperty(T value, bool isReadOnly) {
				Value = value;
				IsReadOnly = isReadOnly;
			}
			virtual T Get() {
				if (OnGet != nullptr) {
					return OnGet(*this);
				}
				return Value;
			}
			virtual void Set(T value) {
				if (OnSet != nullptr) {
					OnSet(*this, value);
				}
				else if (!IsReadOnly) {
					Value = value;
				}
			}
			virtual operator T() {
				return Get();
			}
			virtual void SetOwner(void* owner) {
				this->Owner = owner;
			}
			virtual void* GetOwner() {
				return this->Owner;
			}
		};
	}
}