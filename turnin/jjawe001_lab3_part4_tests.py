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
        'description': 'A:00000000 => B:0000, C:00000.',
        'steps': [ {'inputs': [('PINA',0x00)], 'iterations': 5 } ],
        'expected': [('PORTB', 0x00), ('PORTC',0x00)],
    },
    {
        'description': 'A:11001111 => B:1100, C:11110000.',
        'steps': [ {'inputs': [('PINA',0xCF)], 'iterations': 5 } ],
        'expected': [('PORTB', 0x0C), ('PORTC',0xF0)],
    },
    {
        'description': 'A:10101010 => B:1010, C:10100000.',
        'steps': [ {'inputs': [('PINA',0xAA)], 'iterations': 5 } ],
        'expected': [('PORTB', 0xA), ('PORTC',0xA0)],
    },
    {
        'description': 'A:00101010 => B:0010, C:10100000.',
        'steps': [ {'inputs': [('PINA',0x2A)], 'iterations': 5 } ],
        'expected': [('PORTB', 0x02), ('PORTC',0xA0)],
    },
    { 
        'description': 'A:10000111 => B:1000, C:01110000.',
        'steps': [ {'inputs': [('PINA',0x87)], 'iterations': 5 } ],
        'expected': [('PORTB', 0x08), ('PORTC',0x70)],
    },


]


# Optionally you can add a set of "watch" variables these need to be global or static and may need
# to be scoped at the function level (for static variables) if there are naming conflicts. The 
# variables listed here will display everytime you hit (and stop at) a breakpoint
watch = ['PORTC']

