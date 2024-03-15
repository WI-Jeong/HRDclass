#pragma once

namespace KDT
{
	int Test()
	{
		return 5;
	}

	template<class T>
	class FVectorIterator
	{
	public:
		FVectorIterator() = default;
		FVectorIterator(const FVectorIterator&) = default;
		FVectorIterator(T* InPointer) : Pointer(InPointer) {}
		FVectorIterator& operator=(const FVectorIterator&) = default;

		bool operator==(const FVectorIterator& InIter)
		{
			return Pointer == InIter.Pointer;
		}
		bool operator!=(const FVectorIterator& InIter)
		{
			return Pointer != InIter.Pointer;
		}

		FVectorIterator& operator++()
		{
			if (Pointer)
			{

				++Pointer;
			}
			return *this;
		}

		FVectorIterator operator++(int)
		{
			FVectorIterator Temp = *this;
			FVectorIterator::operator++();
			return Temp;
		}

		FVectorIterator& operator--()
		{
			if (Pointer)
			{
				--Pointer;
			}
			return *this;
		}

		T& operator*() const
		{
			return *Pointer;
		}

		T* operator->() const
		{
			return Pointer;
		}

	private:
		T* Pointer = nullptr;
	};

	template<class T>
	class vector
	{
	public:
		using iterator = FVectorIterator<T>;

		_NODISCARD _CONSTEXPR20 iterator begin() noexcept
		{
			return iterator(Array);
		}

		_NODISCARD _CONSTEXPR20 iterator end() noexcept
		{
			return iterator(Array + Size);
		}

	public:
		void push_back(const T& InData)
		{
			if (IsFull())
			{
				reserve(Size * 2);
			}

			new(Array + Size)T(InData);
			++Size;
		}
		void push_back(T&& InData)
		{
			if (IsFull())
			{
				reserve(Size * 2);
			}

			new(Array + Size)T(std::move(InData));
			++Size;
		}

		void reserve(const size_t InSize)
		{
			const static size_t MinSize = 1;
			const size_t NewSize = std::max(MinSize, InSize) + 1;

			T* NewArray = (T*)malloc(sizeof(T) * NewSize);

			if (!empty())
			{
				for (int i = 0; i < Size; ++i)
				{
					if (i >= (NewSize - 1))
					{
						for (int k = i; k < Size; ++k)
						{
							Array[k].~T();
						}

						Size = i;
						break;
					}

					new(NewArray + i)T(std::move(Array[i]));
					Array[i].~T();
				}
			}

			if (Array)
			{
				free(Array);
				Array = nullptr;
			}

			Array = NewArray;
			Capacity = NewSize - 1;
		}

		void resize(const size_t InSize)
		{
			const size_t OriginSize = Size;
			reserve(InSize);
			for (size_t i = OriginSize; i < InSize; ++i)
			{
				push_back({});
			}
		}

		void clear()
		{
			if (Array == nullptr) { return; }

			for (int i = 0; i < Size; ++i)
			{
				Array[i].~T();
			}

			free(Array);
			Array = nullptr;

			Size = 0;
			Capacity = 0;
		}

		_NODISCARD_EMPTY_MEMBER _CONSTEXPR20 bool empty() const
		{
			return Size == 0;
		}

		_NODISCARD size_t size() const { return Size; }
		_NODISCARD size_t capacity() const { return Capacity; }

		_NODISCARD T& operator[](const size_t InIndex) const
		{
			return Array[InIndex];
		}

	public:
		vector() = default;
		~vector()
		{
			clear();
		}

	private:
		_NODISCARD bool IsFull() const
		{
			return Size == Capacity;
		}

	private:
		T* Array = nullptr;
		size_t Size = 0;			
		size_t Capacity = 0;		
	};
}

