#pragma once
namespace System {
	namespace Util {
		template <typename T> class Property {
		public:
			T Value;
			void* Owner = nullptr;
			bool IsReadOnly = false;
			Property() {

			}
			Property(bool isReadOnly) {
				IsReadOnly = isReadOnly;
			}
			Property(T value) {
				Value = value;
			}
			Property(T value, bool isReadOnly) {
				Value = value;
				IsReadOnly = isReadOnly;
			}
			virtual T Get() {
				return Value;
			}
			virtual void Set(T value) {
				if (!IsReadOnly) {
					Value = value;
				}
			}
			virtual operator T() {
				return Get();
			}
			virtual void SetOwner(void* owner) {
				Owner = owner;
			}
			virtual void* GetOwner() {
				return Owner;
			}
		};
	}
}