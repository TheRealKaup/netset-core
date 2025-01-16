/*
	nsnet, netset's computer network sandbox library.
	Copyright (C) 2025 Ethan Kaufman (AKA Kaup)

	This file is part of nsnet.

	nsnet is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	any later version.

	nsnet is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with nsnet. If not, see <https://www.gnu.org/licenses/>.
*/

/*
	                                               .
	                                             .o8
	ooo. .oo.    .oooo.o ooo. .oo.    .ooooo.  .o888oo
	`888P"Y88b  d88(  "8 `888P"Y88b  d88' `88b   888
	 888   888  `"Y88b.   888   888  888ooo888   888
	 888   888  o.  )88b  888   888  888    .o   888 .
	o888o o888o 8""888P' o888o o888o `Y8bod8P'   "888"  netset's computer network sandbox library

	In order to contact me (Kaup), refer to the "readme.md" file.
*/

/*!
	@brief netset's computer network sandbox library.

	Provides various device classes that can connect to and communicate with each other. Also provides predefined networks. The sandbox is fictional and not realistic (the devices and protocols are obviously much simpler than their real-life counterparts). There are intentionally-implemented vulnerabilities that allow the player to obtain information and complete jobs, as well as optimizing abstractions (for example, rather than actually copying data from device to device as a packet travels the net, the data is kept stationary in memory and only its address is passed around).
*/
namespace nsnet
{
	/*!
		@brief Various devices used to build functional networks.
	*/
	namespace Devices
	{
		/*!
			@brief Abstract device class.

			This is an abstract class; it cannot be instantiated. A network may be created with its derived classes.
		*/
		class Device
		{
			// [...]
			// Called by connected devices to pass a packet to this device.
			virtual void Receive(/*[...]*/) = 0;
			// [...]
		};

		/*!
			@brief Device that passes received packets to a virtual function.
		*/
		class Computer : public Device
		{
			void Receive() override;
		};

		/*!
			@brief Device that distributes received packets to all connected device.

			Dumber version of `Switch`.
		*/
		class Hub : public Device
		{
			void Receive() final;
		};

		/*!
			@brief Device that passes received packets to the designated recipient if it's connected.

			Smarter version of `Hub`.
		*/
		class Switch : public Device
		{
			void Receive() final;
		};

		/*!
			@brief Device that encloses a local network and connects it to a `Net`.

			Defines the public address of a local network.
		*/
		class Modem : public Device
		{
			void Receive() final;
		};

		/*!
			@brief Device that connects and passes packets between `Modem`s.

			There should be 2 instances of this class: one for the internet, another for the darknet.
		*/
		class Net : public Device
		{
			void Receive() final;
		};
	}

	/*!
		@brief Predefined networks.
	*/
	namespace Networks
	{
		/*!
			@brief Email service that lets users create email accounts, login and send and receive emails.

			Should be instantiated once in the internet and the darknet.
		*/
		class EmailProvider;
	}
}