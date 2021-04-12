# Array of tests to run (in order)
# Each test contains
#   description - 
#   steps - A list of steps to perform, each step can have
#       inputs - A list of tuples for the inputs to apply at that step
#       *time - The time (in ms) to wait before continuing to the next step 
#           and before checking expected values for this step. The time should be a multiple of
#           the period of the system
#       *iterations - The number of clock ticks to wait (periods)
#       expected - The expected value at the end of this step (after the "time" has elapsed.) 
#           If this value is incorrect the test will fail early before completing.
#       * only one of these should be used
#   expected - The expected output (as a list of tuples) at the end of this test
# An example set of tests is shown below. It is important to note that these tests are not "unit tests" in 
# that they are not ran in isolation but in the order shown and the state of the device is not reset or 
# altered in between executions (unless preconditions are used).
tests = [
    {
        'description': 'Fuel level 1 or 2. PC6 and PC5 light.',
        'steps': [ {'inputs': [('PINA',0x01)], 'iterations': 5 } ],
        'expected': [('PORTC',0x60)],
    },
    {
        'description': 'Fuel level 3 or 4. PC6, PC5 and PC4 light.',
        'steps': [ {'inputs': [('PINA',0x04)], 'iterations': 5 } ],
        'expected': [('PORTC',0x70)],
    },
    {
        'description': 'Fuel level 5 or 6. PC5, PC4, and PC3 light.',
        'steps': [ {'inputs': [('PINA',0x05)], 'iterations': 5 } ],
        'expected': [('PORTC',0x38)],
    },
    {
        'description': 'Fuel level 7 through 9. PC5, PC4, PC3, PC2 light.',
        'steps': [ {'inputs': [('PINA',0x00)], 'iterations': 5 } ],
        'expected': [('PORTC',0x00)],
    },
    {
        'description': 'Fuel level 10 through 12. PC5, PC4, PC3, PC2, PC1 light.',
        'steps': [ {'inputs': [('PINA',0x0A)], 'iterations': 5 } ],
        'expected': [('PORTC',0x3E)],
    },
     {
        'description': 'Fuel level 13 through 15. PC5, PC4, PC3, PC2, PC1, and PC0 light.',
        'steps': [ {'inputs': [('PINA',0x0E)], 'iterations': 5 } ],
        'expected': [('PORTC',0x3F)],
    },
    {
        'description': 'Fuel level 1 or 2. Seatbelt Unfastened and driver inside.',
        'steps': [ {'inputs': [('PINA',0x31)], 'iterations': 5 } ],
        'expected': [('PORTC',0xE0)],
    },
    {
        'description': 'Fuel level 3 or 4. Seatbelt Unfastened and driver inside.',
        'steps': [ {'inputs': [('PINA',0x34)], 'iterations': 5 } ],
        'expected': [('PORTC',0xF0)],
    },
    {
        'description': 'Fuel level 5 or 6. Seatbelt Unfastened and driver inside.',
        'steps': [ {'inputs': [('PINA',0x36)], 'iterations': 5 } ],
        'expected': [('PORTC',0xB8)],
    },
    {
        'description': 'Fuel level 7, 8, or 9. Seatbelt Unfastened and driver inside.',
        'steps': [ {'inputs': [('PINA',0x38)], 'iterations': 5 } ],
        'expected': [('PORTC',0xBC)],
    },
    {
        'description': 'Fuel level 10, 11, or 12. Seatbelt Unfastened and driver inside.',
        'steps': [ {'inputs': [('PINA',0x3A)], 'iterations': 5 } ],
        'expected': [('PORTC',0xBE)],
    },
    {
        'description': 'Fuel level 13, 14, or 15. Seatbelt Unfastened and driver inside.',
        'steps': [ {'inputs': [('PINA',0x3E)], 'iterations': 5 } ],
        'expected': [('PORTC',0xBF)],
    },

]


# Optionally you can add a set of "watch" variables these need to be global or static and may need
# to be scoped at the function level (for static variables) if there are naming conflicts. The 
# variables listed here will display everytime you hit (and stop at) a breakpoint
watch = ['PORTC']

