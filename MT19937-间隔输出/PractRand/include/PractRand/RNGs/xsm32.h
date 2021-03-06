namespace PractRand {
	namespace RNGs {
		namespace Raw {
			//implemented in RNGs/xsm.cpp
			class xsm32 {
			public:
				enum {
					OUTPUT_TYPE = OUTPUT_TYPES::NORMAL_1,
					OUTPUT_BITS = 32,
					FLAGS = FLAG::ENDIAN_SAFE | FLAG::USES_SPECIFIED | FLAG::USES_MULTIPLICATION | FLAG::SUPPORTS_FASTFORWARD | FLAG::OUTPUT_IS_HASHED
				};
			protected:
				Uint32 lcg_low, lcg_high, lcg_adder, history;
				void step_backwards();
			public:
				Uint32 raw32();
				void seed(Uint64 s);
				void seed(vRNG *seeder_rng);
				void walk_state(StateWalkingObject *walker);
				void seek_forward (Uint64 how_far);
				void seek_backward(Uint64 how_far);
				//static void self_test();
			};
		}
		
		namespace Polymorphic {
			class xsm32 : public vRNG32 {
				PRACTRAND__POLYMORPHIC_RNG_BASICS_H(xsm32)
				void seed(Uint64 s);
				void seed(vRNG *seeder_rng);
				virtual void seek_forward128(Uint64 how_far_low64, Uint64 how_far_high64);
				virtual void seek_backward128(Uint64 how_far_low64, Uint64 how_far_high64);
			};
		}
		PRACTRAND__LIGHT_WEIGHT_RNG(xsm32)
	}
}
