// #include <chrono>

// namespace rbtxpid
// {
// 	class pidController
// 	{
// 		private:
// 			// Constantes pour le PID
// 			float mSetPoint;
// 			float mKproportional;
// 			float mKintegral;
// 			float mKderivative;

// 			// Les variables liées au temps, et aux erreurs
// 			float mLastError;
// 			float mIntegralError;
// 			float mDerivativeError;
// 			std::chrono::steady_clock::time_point mLastTime;

// 			// Mise à jour des variables
// 			void _update(float iError);

// 		public:
// 			// Initialisation du point attendu, et des constantes
// 			pidController(float iKproportional, float iKintegral, float iKderivative);
// 			~pidController();

// 			// Setup du PID
// 			void setPoint(float iSetPoint);
// 			void startTime();


// 			// Retour d'un ouput attendu
// 			float getOutput(float iError);
// 	};
// }

